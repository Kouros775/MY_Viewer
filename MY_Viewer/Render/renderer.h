/* 작성자 : 전민영
 * 목적 : Entity를 상속받아 renderer할 model의 데이터 클래스.
 * RenderBase에 넣을 (계산이 필요한?) 데이터를 구성하는 클래스.
 * 업데이트 날짜 : 22.04.18
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QVector3D>


namespace Qt3DCore
{
    class QEntity;
}
namespace Qt3DRender
{
    class QCamera;
    class QMesh;
    class QPickEvent;
    class QGeometryRenderer;
}
class RenderCamera;
class RenderBase;
class MeshModel;


enum class eMaterialType
{
    PhongMaterial,
    GoochMaterial
};


class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr);
    ~Renderer() override;

    Qt3DCore::QEntity *Initialize(Qt3DRender::QCamera* paramCamera);

    // index, name을 가진 model 생성.
    bool AddModel(const int& paramIndex, const QString& paramName, Qt3DRender::QGeometryRenderer* paramMesh);

    // index의 model 삭제
    bool RemoveModel(const int& paramIndex);

    // model 모두 삭제.
    bool RemoveAllModel();

    // index의 모델 선택
    bool SelectModel(const int& paramIndex);

    // index의 모델의 material 변경.
    bool SetMaterial(const int& paramIndex, const eMaterialType& paramMaterialType);

    // index의 모델의 color 변경.
    bool SetColor(const int& paramIndex, const QColor& paramColor);

    // index의 모델을 이동.
    bool Translate(const int& paramIndex, const QVector3D& startPos, const QVector3D& endPos);

    // index의 모델을 회전.
    bool Rotate(const MeshModel* paramModel, const QVector3D& startPos, const QVector3D& endPos);

    // index의 모델을 크기변환.
    bool Scale(const MeshModel* paramModel, const float& paramDelta);

    // index의 모델을 반환
    MeshModel* GetModel(const int& paramIndex) const;

    // index의 cube 생성.
    void AddCube(const int& paramIndex, const QVector3D paramExtents = QVector3D(40.0f, 40.0f, 40.0f));

    // index의 torus 생성.
    void AddTorus(const int& paramIndex
            , const int& paramRadius =5
            , const int& paramMinorRadius = 1
            , const int & paramRings = 100
            , const int& paramSlices = 20);

    // QObjectPicker의 마우스 이벤트를 받는 slot
private slots:
    void pressed(Qt3DRender::QPickEvent *pick);
    void moved(Qt3DRender::QPickEvent *pick);

private:
    Qt3DCore::QEntity*      rootEntity;  // scene의 rootEntity
    RenderCamera*           camera;      // scene의 카메라
    RenderBase*             renderBase;  // 모델의 데이터를 관리하는 내부 클래스

    QVector3D           startWorldPosition; // 마우스 down point
};

#endif // RENDERER_H
