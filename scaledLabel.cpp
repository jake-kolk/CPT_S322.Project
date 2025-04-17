#include "ScaledLabel.h"

ScaledLabel::ScaledLabel(QWidget* parent)
    : QLabel(parent) {
    setScaledContents(false); // We handle the scaling
    setAlignment(Qt::AlignCenter);
}

void ScaledLabel::setImage(const QPixmap& pixmap) {
    originalPixmap = pixmap;
    updatePixmap();
}

void ScaledLabel::resizeEvent(QResizeEvent* event) {
    QLabel::resizeEvent(event);
    updatePixmap();
}

void ScaledLabel::updatePixmap() {
    if (!originalPixmap.isNull()) {
        QPixmap scaled = originalPixmap.scaledToWidth(width(), Qt::SmoothTransformation);
        setPixmap(scaled);
    }
}
