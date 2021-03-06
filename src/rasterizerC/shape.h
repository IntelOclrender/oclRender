#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <memory>
#include "geometry.h"
#include "image.h"

enum ShapeType
{
	ELLIPSE, CONVEXPOLY
};

class SceneObject
{
public:
  virtual void draw(PPMImage &image, int super_sampling) = 0;
};

class Shape : public SceneObject
{
public:
  Color color;
  AABox bound;
public:
  Shape(const Color *o_color = nullptr);
  virtual bool contains(const Vector &p) const = 0;
  //virtual float signed_distance_bound(const Vector &p) const = 0;
  void draw(PPMImage &image, int super_sampling);
	virtual void get_parameters(std::vector<float> &paras, ShapeType *shapeType) = 0;
	virtual std::shared_ptr<Shape> transformp(const Transform &xform) = 0;
	// TODO: transform return true caller (derived) class obj
	//template <class Shape_drv> // derived class of Shape
	//virtual Shape_drv transform(const Transform &transform) const = 0;
};

#endif //__SHAPE_H__