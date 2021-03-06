/*
 This file is part of Thistle.

	Thistle is free software: you can redistribute it and/or modify
	it under the terms of the Lesser GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License.

	Thistle is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	Lesser GNU General Public License for more details.

	You should have received a copy of the Lesser GNU General Public License
	along with Thistle.    If not, see <http://www.gnu.org/licenses/>.

 Thistle    Copyright (C) 2013    Dimitry Ernot & Romha Korev
*/

#ifndef THISTLE_ABSTRACTITEMVIEW_H
#define THISTLE_ABSTRACTITEMVIEW_H

#include <QAbstractItemView>
#include <QPen>
#include <QPointer>
#include <QRubberBand>

namespace Thistle
{

class ItemDelegate;
class AbstractItemViewPrivate;

class AbstractItemView : public QAbstractItemView
{
	Q_OBJECT
	Q_DECLARE_PRIVATE( AbstractItemView );

protected:
	AbstractItemViewPrivate* d_ptr;

	virtual void setScrollBarValues() = 0;
	QModelIndex moveCursor( QAbstractItemView::CursorAction cursorAction,
							Qt::KeyboardModifiers modifiers );
	void resizeEvent( QResizeEvent* event );

	bool isSelected( const QModelIndex& index ) const;

	AbstractItemView( AbstractItemViewPrivate* d, QWidget* parent = 0 );
public:
	explicit AbstractItemView( QWidget* parent = 0 );
	virtual ~AbstractItemView();

	int horizontalOffset() const;
	int verticalOffset() const;

	bool isIndexHidden( const QModelIndex& index ) const;
	void setSelection( const QRect&, QItemSelectionModel::SelectionFlags command );
	void scrollTo( const QModelIndex& index, ScrollHint hint = EnsureVisible );
	QRect visualRect( const QModelIndex& index ) const;
	QRegion visualRegionForSelection( const QItemSelection& selection ) const;

	virtual QModelIndex indexAt(const QPoint &point) const;
	virtual QRectF itemRect( const QModelIndex& index ) const;
	virtual QRectF itemRect( int row, int column, const QModelIndex& parent = QModelIndex() ) const;
	virtual QPainterPath itemPath( const QModelIndex& index ) const = 0;
	QRegion itemRegion( const QModelIndex &index ) const;

	int rows( const QModelIndex& index ) const;

	virtual void setModel( QAbstractItemModel* model );

	QMargins contentsMargins() const;
	QRect contentsRect() const;

	virtual QSize sizeHint() const;

protected slots:
	void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);
	void rowsAboutToBeRemoved(const QModelIndex& parent, int start, int end);
	void rowsInserted(const QModelIndex &parent, int start, int end);

public slots:
	virtual void updateValues() = 0;
};

}
#endif // THISTLE_ABSTRACTITEMVIEW_H
