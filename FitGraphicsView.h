#ifndef FITGRAPHICSVIEW_H
#define FITGRAPHICSVIEW_H
#include <QGraphicsView>

class FitGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    using QGraphicsView::QGraphicsView;

protected:
    void resizeEvent(QResizeEvent *event) override {
        QGraphicsView::resizeEvent(event);
        if (scene()) {
            fitInView(scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
        }
    }
};

#endif // FITGRAPHICSVIEW_H
