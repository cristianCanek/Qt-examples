#include "customtablemodel.h"

#include <QColor>

CustomTableModel::CustomTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "red"         } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "green"       } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "blue"        } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "yellow"      } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "gray"        } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "black"       } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "aliceblue"   } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "yellowgreen" } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "gray"        } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "white"       } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "green"       } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "gray"        } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "red"         } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "blue"        } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "black"       } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "yellow"      } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "gray"        } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "yellow"      } );
    table.append( { "John", "Doe",  "32", "Farmer",  "Single",  "Gounduana", "white"       } );
    table.append( { "Mary", "Jane", "27", "Teacher", "Married", "Versko",    "blue"        } );
}

int CustomTableModel::rowCount( const QModelIndex &parent) const {
    if ( !parent.isValid() ) {
        return table.size();
    }

    return 0;
}

int CustomTableModel::columnCount( const QModelIndex &parent ) const {
    if ( !parent.isValid() ) {
        return table.at( 0 ).size();
    }

    return 0;
}

QVariant CustomTableModel::data( const QModelIndex &index, int role ) const {
    if ( role == Qt::DisplayRole ) {
        return table.at( index.row() ).at( index.column() );
    }

    if ( role == Qt::DecorationRole && index.column() == 6 ) {
        return QColor( table.at( index.row() ).at( index.column() ) );
    }

    return {};
}

QVariant CustomTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if ( orientation == Qt::Horizontal && role == Qt::DisplayRole ) {
        switch ( section ) {
        case 0:
            return "First Name";
            break;
        case 1:
            return "Last Name";
            break;
        case 2:
            return "Age";
            break;
        case 3:
            return "Proffession";
            break;
        case 4:
            return "Marital Status";
            break;
        case 5:
            return "Country";
            break;
        case 6:
            return "Favorite Color";
            break;
        default:
            return "";
            break;
        }
    }

    return {};
}


bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if ( !(role == Qt::EditRole) ) {
        return false;
    }

    table[ index.row()][ index.column()] = value.toString();

    emit dataChanged( index, index );

    return true;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags( index ) | Qt::ItemIsEditable;
}
