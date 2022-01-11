//
// Created by zimny on 11.01.2022.
//

#ifndef SCRABVISION_RECT_AREA_H
#define SCRABVISION_RECT_AREA_H


#include <QWidget>
#include <utility>

class RectArea : public QWidget{

    Q_OBJECT

public:
    RectArea(QWidget *parent = nullptr);
    bool isModified() const {return modified;}
    void setImage(QImage img) {image = std::move(img); modified = true;}
public slots:
    void clearImage();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;



private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified = false;
    bool drawing = false;
    int penWidth = 1;
    QColor penColor = Qt::blue;

    QImage image;
    QPoint lastPoint;
};


#endif //SCRABVISION_RECT_AREA_H
