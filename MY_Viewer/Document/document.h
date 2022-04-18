/* 작성자 : 전민영
 * 목적 : model index를 관리하기 위한 Document
 * 업데이트 날짜 : 22.04.18
 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>

class Document : public QObject
{
    Q_OBJECT
public:
    static Document& Instance()
    {
        static Document instance;
        return instance;
    }

    void SetAddIndex(const int& paramIndex){this->addIndex = paramIndex;}
    int GetAddIndex() const {return this->addIndex;}

    void SetSelectedIndex(const int& paramIndex);
    int GetSelectedIndex() const {return this->selectedIndex;}

signals:
    void signalSelectItem(const int& paramIndex);
private:
    explicit Document(QObject *parent = nullptr);
    ~Document();

private:
    int     addIndex; // 추가할 model의 index
    int     selectedIndex; // 선택한 model index
};

#endif // DOCUMENT_H
