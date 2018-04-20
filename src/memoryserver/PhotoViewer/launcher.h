/**
 * @brief This is the class to start all program and other modules.
 * 
 * @file launcher.h
 * @authors Generated by qt, modified by aleklnx
 * @date 2018-03-19
 */

#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class Launcher;
}

class MemoryViewer;
class SocketManager;
class MemoryManager;

class Launcher : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Launcher object
     * 
     * @param parent Is a pointer used by Qt.
     */
    explicit Launcher(QWidget *parent = 0);
    /**
     * @brief Destroy the Launcher object
     * 
     */
    ~Launcher();

private slots:

    /**
     * @brief method to detect the the press of button for start the server.
     */
    void on_button_startServer_clicked();

    /**
     * @brief method to detect the the press of button for quit the app.
     */
    void on_button_quitApp_clicked();

    /**
     * @brief method to detect the the press of button for send messages.
     */
    void on_button_test_clicked();

private:

    Ui::Launcher *ui;
    /**
     * @brief This is the server socket information.
     */
    SocketManager * localServer;
    /**
     * @brief Instance of memory manager, this controls the virtual pages and all about it.
     */
    MemoryManager * menMan;
    /**
     * @brief instance of window which show up the info of virtual pages.
     */
    MemoryViewer * monitor;
};

#endif // LAUNCHER_H