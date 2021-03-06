#ifndef AXESTOBUTTONSSLIDER_H
#define AXESTOBUTTONSSLIDER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE
//#include <QLabel>

#include "global.h"
#include "deviceconfig.h"

#define MAX_A2B_BUTTONS 12

namespace Ui {
class AxesToButtonsSlider;
}

class AxesToButtonsSlider : public QWidget
{
    Q_OBJECT

public:
    explicit AxesToButtonsSlider(QWidget *parent = nullptr);
    ~AxesToButtonsSlider();

    void SetPointsCount(uint count);
    uint GetPointsCount();

    void SetPointValue(uint value, uint point_number);
    uint GetPointValue(uint point_number);

    void SetAxisOutputValue(int out_value, bool is_enable);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent*) override;
    bool event(QEvent *event) override;

private:
    Ui::AxesToButtonsSlider *ui;
    void DrawPoint(QPoint point_pos, uint range_points);
    void MovePointer(uint pos_x, uint point_number);
    uint CalcPointValue(int current_pos);
    void PointsPositionReset();
    void SetLableValue(int point_pos ,uint point_number);

    float line_spacing_;

    float axis_output_value_;
    int axis_output_width_;
    bool is_out_enabled_;

    const QColor kAxisRectColor = QColor(160, 0, 0);
    const QColor kAxisRectColor_dis = QColor(160, 0, 0, 80);
    const QColor kPointRawActivColor = QColor(0, 170, 0);
    QColor axis_rect_color_;

    const int half_pointer_width = 4;

    const QColor pointer_color_ = QColor(1,119,215);
    const uint max_point_value_ = 255;
    const int offset_ = 10;
    const int range_between_ = 13;  // минимальное расстояние между ближайшими указателями
    const int label_width_ = 20;
    const int kMinHeight_ = 40;//45  // переименовать константы в такой стиль

    const int padding_top_ = 7;
    const QPoint pointer[5]={
        QPoint(-half_pointer_width,2),// + padding_top_
        QPoint(-half_pointer_width,12),
        QPoint(0,20),
        QPoint(half_pointer_width,12),
        QPoint(half_pointer_width,2),
    };

    uint points_count_;

    QList<QLabel*> LabelAdrList;


    struct A2B_point    // uint гемороя наделал
    {
        QPolygon polygon;
        QColor color;
        QLabel* text_label;
        uint posX;
        uint current_value;
        bool is_drag;
    };
     QList<A2B_point*> PointAdrList;

};

#endif // AXESTOBUTTONSSLIDER_H
