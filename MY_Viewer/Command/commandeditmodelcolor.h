/* 작성자 : 전민영
 * 목적 : 선택한 모델의 Color를 변경하기 위한 커맨드
 * 업데이트 날짜 : 22.04.18
 */
#ifndef COMMANDEDITMODELCOLOR_H
#define COMMANDEDITMODELCOLOR_H

#include "Command/icommand.h"


class QColor;


class CommandEditModelColor : public ICommand
{
    Q_OBJECT
public:
    explicit CommandEditModelColor(QObject *parent=nullptr);
    ~CommandEditModelColor() override;
    void Execute() override;

    // 선택한 index의 model의 Color를 변경하라는 signal
signals:
    void EditModelColor(const int& paramindex, const QColor& paramColor);
};

#endif // COMMANDEDITMODELCOLOR_H
