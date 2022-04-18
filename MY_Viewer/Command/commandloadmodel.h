/* 작성자 : 전민영
 * 목적 : stl,obj,ply 모델을 로드하는 커맨드
 * 업데이트 날짜 : 22.04.18
 */

#ifndef COMMANDLOADMODEL_H
#define COMMANDLOADMODEL_H

#include "Command/icommand.h"


namespace Qt3DRender
{
    class QMesh;
    class QGeometryRenderer;
}
class QListWidget;


class CommandLoadModel : public ICommand
{
    Q_OBJECT
public:
    explicit CommandLoadModel(QObject *parent=nullptr);
    ~CommandLoadModel() override;
    void Execute() override;

    void SetListWidget(QListWidget* param){this->listWidget = param;}

    // Load한 mesh를 model index번호와 함께 렌더러에 보냄.
signals:
    void AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);

private:
    QListWidget*    listWidget;   // 우측에 있는 ModelList 위젯
};

#endif // COMMANDLOADMODEL_H
