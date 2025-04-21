#include "FitGraphicsView.h"

FitGraphicsView::FitGraphicsView(QWidget* parent)
    : QGraphicsView(parent) {}

// void FitGraphicsView::resizeEvent(QResizeEvent* event) {
//     QGraphicsView::resizeEvent(event);
//     if (scene() && !scene()->items().isEmpty()) {
//         fitInView(scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
//     }
// }
void FitGraphicsView::resizeEvent(QResizeEvent* event) {
    QGraphicsView::resizeEvent(event);

    if (!scene() || scene()->items().isEmpty())
        return;

    // Get the bounding rect of all items (usually the image)
    QRectF itemsRect = scene()->itemsBoundingRect();

    // Calculate scale to fit width
    qreal viewWidth = viewport()->width();
    qreal itemWidth = itemsRect.width();

    if (itemWidth == 0) return; // Avoid division by zero

    qreal scale = viewWidth / itemWidth;

    // Reset any previous transform
    resetTransform();

    // Apply the new transform (scaled uniformly to maintain aspect ratio)
    scaleTransform(scale);

    // Center the view vertically
    centerOn(itemsRect.center());
}

void FitGraphicsView::scaleTransform(qreal scaleFactor) {
    QTransform transform;
    transform.scale(scaleFactor, scaleFactor);
    setTransform(transform);
}
