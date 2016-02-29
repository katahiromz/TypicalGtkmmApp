// MainWindow.cpp --- main window                               -*- C++ -*-
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow() {
    set_title("TypicalGtkmmApp");
    set_size_request(300, 150);

    set_border_width(10);

    m_label.set_text("Hello, world!");

    m_button.set_label("Click me!");
    m_button.signal_clicked().connect(
        sigc::mem_fun(*this, &MainWindow::on_button_clicked)
    );

    m_vbox.pack_start(m_label);
    m_vbox.pack_start(m_button, Gtk::PACK_SHRINK);

    m_vbox.set_border_width(10);
    add(m_vbox);

    show_all_children();
} // MainWindow::MainWindow

MainWindow::~MainWindow() {
    ;
} // MainWindow::~MainWindow

void MainWindow::on_button_clicked() {
    printf("Hello, world\n");
    hide();
}

//////////////////////////////////////////////////////////////////////////////
