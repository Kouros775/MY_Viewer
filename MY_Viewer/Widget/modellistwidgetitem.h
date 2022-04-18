/* 작성자 : 전민영
 * 목적 : ListWidget에 있는 item 클래스
 * 업데이트 날짜 : 22.04.18
 */

#ifndef MODELLISTWIDGETITEM_H
#define MODELLISTWIDGETITEM_H


#include <QListWidgetItem>
#include <QObject>


class ModelListWidgetItem : public QListWidgetItem
{
    //Q_OBJECT
public:
    explicit ModelListWidgetItem(const QIcon &icon, const QString &text,
                             QListWidget *view = nullptr, int type = Type);
    ~ModelListWidgetItem() override;

    void SetIndex(const int& paramIndex){index = paramIndex;}
    int GetIndex() const {return index;}

    void SetName(const QString& paramName){name = paramName;}
    QString GetName() const {return name;}
private:
    int index;      // 모델의 index
    QString name;   // 모델의 이름.
};

#endif // MODELLISTWIDGETITEM_H
