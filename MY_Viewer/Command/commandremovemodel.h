/* 작성자 : 전민영
 * 목적 : 해당 index의 모델 삭제하라는 커맨드
 * 업데이트 날짜 : 22.04.18
 */
#ifndef COMMANDREMOVEMODEL_H
#define COMMANDREMOVEMODEL_H

#include "Command/icommand.h"


class QListWidget;


class CommandRemoveModel : public ICommand
{
    Q_OBJECT
public:
    explicit CommandRemoveModel(QObject *parent=nullptr);
    virtual ~CommandRemoveModel();
    virtual void Execute();

    void SetListWidget(QListWidget* param){this->listWidget = param;}

    // 해당 index의 모델을 삭제하라는 신호
signals:
    void RemoveModel(const int& paramIndex);

private:
    QListWidget*    listWidget;
};


#endif // COMMANDREMOVEMODEL_H
