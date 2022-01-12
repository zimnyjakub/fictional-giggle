//
// Created by zimny on 11.01.2022.
//

#include "rect_area.h"
#include <QMouseEvent>
#include <QPainter>
#include <utility>

RectArea::RectArea(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_StaticContents);
}

void RectArea::clearImage() {
    image = originalImage;
    lastPoint = QPoint();
    update();
}

void RectArea::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && lastPoint.isNull()) {
        lastPoint = event->pos();
        startPoint = event->pos();
        drawing = true;
    }
}

void RectArea::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        drawRectangleTo(event->pos());
    }
}

void RectArea::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        QPainter painter(&image);
        painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawRect(tempRect);
        update();
        drawing = false;

        emit rectChanged(tempRect);
    }
}

void RectArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
    if (drawing) {
        painter.drawRect(tempRect);
    }
}

void RectArea::resizeEvent(QResizeEvent *event) {
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void RectArea::resizeImage(QImage *image, const QSize &newSize) {
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void RectArea::drawRectangleTo(const QPoint &endPoint) {
    QPainter painter(&image);
    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    tempRect = QRect(startPoint.x(), startPoint.y(), endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());
    update();
}
