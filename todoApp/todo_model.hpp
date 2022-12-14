#include <QAbstractListModel>

#include <tuple>

#include <QImage>

class TodoModel : public QAbstractListModel
{

    Q_OBJECT

private:
    std::vector<std::tuple<bool, QString>> todos;
    QImage done_img;
    QImage todo_img;

public:
    TodoModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::ItemDataRole::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    void add_todo(QString newTodo);
    void delete_todo(int index);
    void complete_todo(int index);
};
