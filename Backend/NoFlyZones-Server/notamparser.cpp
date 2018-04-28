#include "notamparser.h"


QJsonArray NotamParser::notamXmlToJson(QString xmlNotamList)
{
    (void) xmlNotamList;

    return null;
}

/*!
 * \brief NotamParser::DMStoDDConverter
 * Converts Degrees, Minutes, Seconds notation to Degrees Decimal
 * \param DMSValue
 * The DMS value to be converted to DD notation
 * \return
 * Returns the given DMS value in DD notation
 */
double NotamParser::DMStoDDConverter(QString DMSValue)
{
    double value = 0.0;

    // Check if the DMS value is valid
    if(DMSValue.length() != 6) {
        return value;
    }

    // Split the value into degrees, minutes & seconds
    double degrees = DMSValue.left(2) .toInt();
    double minutes = DMSValue.mid(2,2).toInt();
    double seconds = DMSValue.right(2).toInt();

    value = degrees + (minutes / 60) + (seconds / 3600);

    return value;
}
