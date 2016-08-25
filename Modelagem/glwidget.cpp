#include "glwidget.h"

#include <QDebug>
#include <QMouseEvent>
#include <QWheelEvent>

const int kFPS = 60;

GLWidget::GLWidget(QWidget *parent) : rotX(0), rotY(0), zoom(0),
                                      QOpenGLWidget(parent) {
  autoTimer.setInterval(1000 / kFPS);
  connect(&autoTimer, SIGNAL(timeout()), this, SLOT(AutoRotate()));
}

void GLWidget::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
}

void GLWidget::resizeGL(int w, int h) {
  qDebug() << "Resize";
  float ratio = (float)w / (float)h;
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (ratio > 1.0f) {
    glFrustum(-0.1, 0.1, -0.1 / ratio, 0.1 / ratio, 0.1, 1000);
  } else {
    glFrustum(-0.1 * ratio, 0.1 * ratio, -0.1, 0.1, 0.1, 1000);
  }
  glTranslatef(0, 0, -3);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

#include "octree/octree.h"
void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0, 0, zoom);
  glRotatef(rotX, 1, 0, 0);
  glRotatef(rotY, 0, 1, 0);
  //  glBegin(GL_LINES);
  //  glColor3f(1, 0, 0);
  //  glVertex3f(0, 0, 0);
  //  glVertex3f(1, 0, 0);
  //  glColor3f(0, 1, 0);
  //  glVertex3f(0, 0, 0);
  //  glVertex3f(0, 1, 0);
  //  glColor3f(0, 0, 1);
  //  glVertex3f(0, 0, 0);
  //  glVertex3f(0, 0, 1);
  //  glEnd();

  glColor3f(1, 1, 1);
  OctreeNode *node1 = new OctreeFull();
  OctreeNode *node2 = new OctreeEmpty();
  OctreePartial *root = new OctreePartial();
  root->nodes[0] = node2;
  root->nodes[1] = node1;
  Octree oct(root);
  float spread = 0.5f;
  oct.Draw(spread);
}

void GLWidget::mousePressEvent(QMouseEvent *e) {
  previousPos = e->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *e) {
  delta = e->pos() - previousPos;
  previousPos = e->pos();

  rotX += delta.y();
  rotY += delta.x();

  update();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *e) {
  if (delta.manhattanLength() > 5) {
    autoTimer.start();
  } else {
    autoTimer.stop();
  }
}

void GLWidget::wheelEvent(QWheelEvent *e) {
  zoom += (float)e->delta()/100.0f;
  update();
}

void GLWidget::AutoRotate() {
  rotX += delta.y() * 0.2f;
  rotY += delta.x() * 0.2f;

  update();
}
