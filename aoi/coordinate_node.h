#ifndef OPAS_COORDINATE_NODE_H
#define OPAS_COORDINATE_NODE_H
#include "common.h"
namespace OPASEngine {
#define COORDINATE_NODE_FLAG_UNKNOWN				0x00000000
#define COORDINATE_NODE_FLAG_ENTITY					0x00000001		// 一个Entity节点
#define COORDINATE_NODE_FLAG_TRIGGER				0x00000002		// 一个触发器节点
#define COORDINATE_NODE_FLAG_HIDE					0x00000004		// 隐藏节点(其他节点不可见)
#define COORDINATE_NODE_FLAG_REMOVING				0x00000008		// 删除中的节点
#define COORDINATE_NODE_FLAG_REMOVED				0x00000010		// 删除节点
#define COORDINATE_NODE_FLAG_PENDING				0x00000020		// 这类节点处于update操作中。
#define COORDINATE_NODE_FLAG_ENTITY_NODE_UPDATING	0x00000040		// entity节点正在执行update操作
#define COORDINATE_NODE_FLAG_INSTALLING				0x00000080		// 节点正在安装操作
#define COORDINATE_NODE_FLAG_POSITIVE_BOUNDARY		0x00000100		// 节点是触发器的正边界
#define COORDINATE_NODE_FLAG_NEGATIVE_BOUNDARY		0x00000200		// 节点是触发器的负边界

#define COORDINATE_NODE_FLAG_HIDE_OR_REMOVED		(COORDINATE_NODE_FLAG_REMOVED | COORDINATE_NODE_FLAG_HIDE)
class CoordinateSystem;
class CoordinateNode
{
    public: 
    CoordinateNode( CoordinateSystem* pCoordinateSystem = NULL);
    virtual ~CoordinateNode();
    INLINE void flags(uint32 v);
    INLINE uint32 flags() const;
    INLINE void addFlags(uint32 v);
    INLINE void removeFlags(uint32 v);
    INLINE bool hasFlags(uint32 v) const;
    /**
		(节点本身的坐标)
		x && z由不同的应用实现(从不同处获取)
	*/
    virtual float x() const { return x_; }
    virtual float y() const { return y_; }
    virtual float z() const { return z_; }

	virtual void x(float v) { x_ = v; }
	virtual void y(float v) { y_ = v; }
	virtual void z(float v) { z_ = v; }
    /**
		(扩展坐标)
		x && z由不同的应用实现(从不同处获取)
	*/
	virtual float xx() const { return 0.f; }
	virtual float yy() const { return 0.f; }
	virtual float zz() const { return 0.f; }

	void old_xx(float v) { old_xx_ = v; }
	void old_yy(float v) { old_yy_ = v; }
	void old_zz(float v) { old_zz_ = v; }

	float old_xx() const { return old_xx_; }
	float old_yy() const { return old_yy_; }
	float old_zz() const { return old_zz_; }

	int8 weight() const { return weight_; }
};
}
#endif