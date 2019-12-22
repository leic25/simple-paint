#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QSize>
#include <QDebug>
#include <QColor>
#include <QPoint>
#include <QMouseEvent>
#include <QWidget>
#include <QColorDialog>
#include <QObject>

#include "qpainter.h"

#include "headers/tool.h"
#include "headers/pencil.h"
#include "headers/eraser.h"
#include "headers/colorpicker.h"
#include "headers/brush.h"

class image: public QWidget {

public:
    image(QWidget *parent = nullptr);
    ~image() override;

    // the image was modified?
    bool isModified() const { return modified; }
    QColor penColor() const { return myColor; }
    QImage getImage() const { return img; }

public slots:
    void clearImage();
    void setPenColor();
    void setTool(QString nameOfTool);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &filename, const char *fileFormat);


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void resizeImage(QImage *img, const QSize &newSize);

    bool modified;                 // saved after a change?
    bool whiteBackground;         //initial background

    int myWidth;

    QColor myColor;
    QImage img;
    QPoint lastPoint;
    Tool *tool;
    std::map<QString, Tool*> allTools;

};

#endif // IMAGE_H