#include "commandeditmodelcolor.h"
#include <QColorDialog>
#include "Document/document.h"


CommandEditModelColor::CommandEditModelColor(QObject *parent)
    : ICommand(parent)
{
}

CommandEditModelColor::~CommandEditModelColor()
{
}


// 선택한 컬러로 모델 변경,
void CommandEditModelColor::Execute()
{
    // 컬러 선택.
    QColor color;
    color = QColorDialog::getColor(Qt::green, nullptr, "컬러선택" ,
     QColorDialog::DontUseNativeDialog);
    if (color.isValid())
    {
        // 변경하라는 신호
        emit EditModelColor(Document::Instance().GetSelectedIndex(), color);
    }

}
