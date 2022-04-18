#include "commandaddcube.h"
#include "Document/document.h"
#include <QListWidget>

#include "Widget/modellistwidgetitem.h"


#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"


CommandAddCube::CommandAddCube(QObject *parent)
    : ICommand(parent)
    , listWidget(nullptr)
{

}

CommandAddCube::~CommandAddCube()
{

}


// 1. 모델에 index와 이름 set
// 2. 렌더러에 signal 던지기.
void CommandAddCube::Execute()
{
    int addIndex = Document::Instance().GetAddIndex();
    QString itemText = "Cube";

    ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
    item->SetIndex(addIndex);
    item->SetName("Cube");

    listWidget->addItem(item);
    listWidget->setCurrentItem(item);


    emit AddCube(addIndex);
    Document::Instance().SetAddIndex(addIndex + 1);
    Document::Instance().SetSelectedIndex(addIndex);
}
