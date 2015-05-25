#ifndef THISTLE_LINEARLEGENDCHART_H
#define THISTLE_LINEARLEGENDCHART_H

#include <QPainter>
#include <QRect>

#include "../base/abstractchartlegend.h"

namespace Thistle
{
class LinearChart;
class LinearChartLegend : public AbstractChartLegend
{
protected:
    LinearChart* chart;
    virtual void paintSerie( QPainter &painter, int serie, QPoint pos, int maxHeight ) const;
public:
    QRect area;
    LinearChartLegend( LinearChart* parent );
    ~LinearChartLegend();
private:

};
}

#endif // THISTLE_LINEARLEGENDCHART_H
