/* 작성자 : 전민영
 * 목적 : Renderer가 전해준 Model 데이터를 관리하는 클래스
 * 업데이트 날짜 : 22.04.18
 */

#ifndef RENDERBASE_H
#define RENDERBASE_H

#include <QObject>
#include <QMap>


namespace Qt3DCore
{
    class QEntity;
}
class MeshModel;


class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    ~RenderBase();
    Qt3DCore::QEntity* Initialize(); // rootEntity를 생성 및 반환

    bool AddModel(const int& paramIndex, MeshModel* paramModel);
    bool RemoveModel(const int& paramIndex);
    bool RemoveAllModel();
    bool IsEmptyIndex(const int& paramIndex) const;

    MeshModel* GetModel(const int& paramIndex) const;
    QMap<int, MeshModel*>* GetModelMap();

private:
    Qt3DCore::QEntity*                  rootEntity; // scene의 rootEntity
    QMap<int, MeshModel*>               modelMap;  // Model 데이터를 index와 함께 관리하는 map
};

#endif // RENDERBASE_H
