//
// Created by zimny on 11.01.2022.
//

#ifndef SCRABVISION_RECT_AREA_H
#define SCRABVISION_RECT_AREA_H


#include <QWidget>
#include <utility>

class RectArea : public QWidget {

Q_OBJECT

public:
    RectArea(QWidget *parent = nullptr);

    void setImage(const QImage& img) {
        originalImage = img,
        image = img;
    }

public slots:

    void clearImage();

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

signals:
    void rectChanged(const QRect& rect);



private:

    void drawRectangleTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool drawing = false;
    int penWidth = 1;
    QColor penColor = Qt::blue;

    QImage image;
    QPoint lastPoint;
    QPoint startPoint;

    QImage originalImage;
    QRect tempRect;
};


#endif //SCRABVISION_RECT_AREA_H
