#include "routeplace.h"
#include "routecoordinateitem.h"
#include "routeaddress.h"

RoutePlace::RoutePlace(QObject *parent)
    : QObject(parent)
    , m_address(0)
    , m_coordinate(0)
{
}

RoutePlace::~RoutePlace()
{
}

RouteCoordinateItem* RoutePlace::coordinate()
{
    return m_coordinate;
}

void RoutePlace::setCoordinate(RouteCoordinateItem *coordinate)
{
    m_coordinate = coordinate;
    emit coordinateChanged();
}

RouteAddress* RoutePlace::address()
{
    return m_address;
}

void RoutePlace::setAddress(RouteAddress* address)
{
    m_address = address;
    emit addressChanged();
}

void RoutePlace::setGeoPlace(const QGeoPlace &place)
{
    m_place = place;
    m_address = new RouteAddress;
    m_address->setGeoAddress(place.address());
}
