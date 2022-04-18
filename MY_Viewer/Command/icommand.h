/* 작성자 : 전민영
 * 목적 : 커맨드 인터페이스 클래스
 * 업데이트 날짜 : 22.04.18
 */
#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <QObject>

class ICommand : public QObject
{
    Q_OBJECT
public:
    explicit ICommand(QObject *parent=nullptr);
    virtual ~ICommand() = default;

public:
    virtual void Execute() = 0;

};

#endif // ICOMMAND_H
