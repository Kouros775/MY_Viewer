/* 작성자 : 전민영
 * 목적 : Entity를 상속받아 renderer할 model의 데이터 클래스.
 * 업데이트 날짜 : 22.04.18
 */

#ifndef MESHMODEL_H
#define MESHMODEL_H

#include <Qt3DCore/QEntity>
#include <QObject>
#include <QColor>


namespace Qt3DCore
{
    class QTransform;
}
namespace Qt3DRender
{
    class QMaterial;
    class QGeometryRenderer;
}


class MeshModel : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit MeshModel(Qt3DCore::QEntity* parent = nullptr);
    ~MeshModel() override;

    void SetIndex(const int& paramIndex){this->index = paramIndex;}
    int GetIndex() const {return index;}

    void SetColor(const QColor& paramColor){this->color = paramColor;}
    QColor GetColor() const {return this->color;}

    Qt3DCore::QTransform* GetTransform() const;
    Qt3DRender::QMaterial* GetMaterial() const;
    Qt3DRender::QGeometryRenderer* GetGeometryRenderer() const;
private:
    int index; // 모델의 index
    QColor color; // 모델의 color
};

#endif // MESHMODEL_H
