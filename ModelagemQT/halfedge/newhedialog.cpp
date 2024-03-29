#include "newhedialog.h"
#include "ui_newhedialog.h"

#include "halfedge/halfedgeobject.h"
#include "scene.h"

NewHEDialog::NewHEDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::NewHEDialog)
{
  ui->setupUi(this);

  ui->stackedWidget->setCurrentWidget(ui->invalid_page);

  QObject::connect(ui->box_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->cylinder_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->cone_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->torus_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->sphere_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->prism_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->pyramid_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
}

NewHEDialog::~NewHEDialog()
{
  delete ui;
}

void NewHEDialog::CreateHE(Scene *scene)
{
  HalfEdgeObject * object = new HalfEdgeObject();
  switch (shape) {
  case Sphere:
    object->CreateSphere(ui->sphere_radius->value()/2.0f);
    break;
  case Cylinder:
    object->CreatePrysm(ui->cylinder_radius->value()/2.0f,ui->cylinder_height->value(),20);
    break;
  case Box:
    object->CreateBox(ui->box_w->value(),ui->box_h->value(),ui->box_d->value());
    break;
  case Torus:
    object->CreateTorus(ui->torus_r1->value()/2.0f, ui->torus_r2->value()/2.0f);
    break;
  case Cone:
    object->CreatePyramid(ui->cone_radius->value()/2.0f, ui->cone_height->value(),20);
    break;
  case Pyramid:
    object->CreatePyramid(ui->pyramid_diameter->value()/2.0f,ui->pyramid_height->value(),ui->pyramid_sides->value());
    break;
  case Prism:
    object->CreatePrysm(ui->prism_diameter->value()/2.0f,ui->prism_height->value(),ui->prism_sides->value());
    break;
  default:
    delete object;
    object = nullptr;
    break;
  }
  if(object!=nullptr){
    scene->CreateObjectGeneric(object);
  }
}

void NewHEDialog::SelectPrimitiveShape(bool checked)
{
  if (!checked) {
    return;
  }
  QRadioButton *rb = qobject_cast<QRadioButton *>(QObject::sender());
  if (rb != nullptr) {
    if (rb->text() == "Sphere") {
      ui->stackedWidget->setCurrentWidget(ui->sphere_page);
      shape = Sphere;
    } else if (rb->text() == "Cylinder") {
      ui->stackedWidget->setCurrentWidget(ui->cylinder_page);
      shape = Cylinder;
    } else if (rb->text() == "Box") {
      ui->stackedWidget->setCurrentWidget(ui->box_page);
      shape = Box;
    } else if (rb->text() == "Cone") {
      ui->stackedWidget->setCurrentWidget(ui->cone_page);
      shape = Cone;
    } else if (rb->text() == "Torus") {
      ui->stackedWidget->setCurrentWidget(ui->torus_page);
      shape = Torus;
    } else if (rb->text() == "Pyramid") {
      ui->stackedWidget->setCurrentWidget(ui->pyramid_page);
      shape = Pyramid;
    } else if (rb->text() == "Prism") {
      ui->stackedWidget->setCurrentWidget(ui->prism_page);
      shape = Prism;
    } else {
      ui->stackedWidget->setCurrentWidget(ui->invalid_page);
      shape = Invalid;
    }
  }
}
