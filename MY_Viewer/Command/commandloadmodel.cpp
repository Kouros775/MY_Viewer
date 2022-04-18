#include "commandloadmodel.h"
#include <QFileDialog>
#include <QApplication>
#include <QStandardPaths>
#include <Qt3DRender/QMesh>

#include "Document/document.h"
#include "Widget/modellistwidgetitem.h"


#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"


CommandLoadModel::CommandLoadModel(QObject *parent)
    : ICommand(parent)
    , listWidget(nullptr)
{
}

CommandLoadModel::~CommandLoadModel()
{
}


// 1. 원하는 경로의 model 로드.
// 2. 모델에 index와 이름 set
// 3. 렌더러에 signal 던지기.
void CommandLoadModel::Execute()
{
    QString path = QFileDialog::getOpenFileName(nullptr
                                                , "파일 선택"
                                                , QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
                                                , "stl (*.stl) ;; obj (*.obj) ;; ply (*.ply)");

    if(path.size() > 0)
    {
        Qt3DRender::QMesh* loadMesh = new Qt3DRender::QMesh; // load하는 모델

        QUrl urlPath = QUrl::fromLocalFile(path);

        QString meshName = path.section("/", -1);

        loadMesh->setMeshName(meshName);
        loadMesh->setSource(urlPath);

        int addIndex = Document::Instance().GetAddIndex();
        QString itemText = loadMesh->meshName();

        ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
        item->SetIndex(addIndex);
        item->SetName(loadMesh->meshName());

        listWidget->addItem(item);
        listWidget->setCurrentItem(item);

        // 렌더러에 신호 보내기.
        emit AddModel(addIndex, loadMesh);

        // document에 index 재설정.
        Document::Instance().SetAddIndex(addIndex + 1);
        Document::Instance().SetSelectedIndex(addIndex);
    }
}
