#include "todo_model.hpp"

TodoModel::TodoModel(QObject *parent) : QAbstractListModel(parent)
{
    todos = {std::make_tuple<bool, QString>(true, "Create initial todoApp"),
             std::make_tuple<bool, QString>(false, "Finish todoApp")};

    done_img = QImage("icons/tick.png");
    todo_img = QImage("icons/cross.png");
}

QVariant TodoModel::data(const QModelIndex &index, int role) const
{
    bool status = std::get<0>(todos[index.row()]);
    QString text = std::get<1>(todos[index.row()]);

    if (role == Qt::ItemDataRole::DisplayRole)
    {
        return text;
    }
    else if (role == Qt::ItemDataRole::DecorationRole)
    {
        return status ? done_img : todo_img;
    }

    return QVariant();
}

int TodoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(todos.size());
}

void TodoModel::add_todo(QString newTodo)
{
    todos.push_back(std::make_tuple<bool, QString>(false, QString(newTodo))); // ??
    qDebug() << "Added new todo: " << newTodo;
}

void TodoModel::delete_todo(int index)
{
    todos.erase(todos.begin() + index);
    qDebug() << "Deleted item at index " << index;
}

void TodoModel::complete_todo(int index)
{
    std::get<0>(todos.at(index)) = true;
    qDebug() << "Item at index " << index << "was complete";
}
