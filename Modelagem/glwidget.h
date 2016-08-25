#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QPoint>
#include <QTimer>

class GLWidget : public QOpenGLWidget {
  Q_OBJECT
public:
  explicit GLWidget(QWidget *parent = 0);

  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

  void mousePressEvent(QMouseEvent *e);
  void mouseMoveEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);
  void wheelEvent(QWheelEvent *e);

private:
  QPoint previousPos;
  float rotX;
  float rotY;
  float zoom;
  QPoint delta;

  QTimer autoTimer;

public slots:
  void AutoRotate();
};

#endif // GLWIDGET_H
