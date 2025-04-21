#ifndef SCALEDLABEL_H
#define SCALEDLABEL_H

#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>


class ScaledLabel : public QLabel {
    QPixmap originalPixmap;

public:
    ScaledLabel(QWidget* parent = nullptr);

    void setImage(const QPixmap& pixmap);

protected:
    void resizeEvent(QResizeEvent* event);

private:
    void updatePixmap();
};

#endif // SCALEDLABEL_H
