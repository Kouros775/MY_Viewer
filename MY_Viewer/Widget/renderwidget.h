/* 작성자 : 전민영
 * 목적 : 3DWindow를 들고있는 위젯 클래스.
 * 업데이트 날짜 : 22.04.18
 */

#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>


class RenderWindow;


class RenderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = nullptr);
    ~RenderWidget() override;

    QSize sizeHint() const override;

    RenderWindow* GetRenderWindow() const {return renderWindow;}


private:
    RenderWindow* renderWindow;
};

#endif // RENDERWIDGET_H
