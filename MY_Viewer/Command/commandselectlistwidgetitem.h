/* 작성자 : 전민영
 * 목적 : 위젯을 선택하면 선택 index 변경.
 * 업데이트 날짜 : 22.04.18
 */
#ifndef COMMANDSELECTLISTWIDGETITEM_H
#define COMMANDSELECTLISTWIDGETITEM_H

#include "Command/icommand.h"


class QListWidgetItem;


class CommandSelectListWidgetItem : public ICommand
{
    Q_OBJECT
public:
    explicit CommandSelectListWidgetItem(QObject *parent=nullptr);
    virtual ~CommandSelectListWidgetItem() override;
    void Execute() override;

    // 선택한 위젯 변경
public slots:
    void ItemPressed(QListWidgetItem* item);

//signals:
//    void SelectModel(const int& paramindex);

};

#endif // COMMANDSELECTLISTWIDGETITEM_H
