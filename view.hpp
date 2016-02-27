#pragma once

#include <QObject>
#include <Qt/QtGui>

class translator;

class view : public QWidget
{
    Q_OBJECT

    friend class translator;
    private :
        
        QPushButton m_equal ;
        QComboBox m_operators ;
        QSpinBox m_first_operand;
        QSpinBox m_second_operand;
        QLabel m_result;


    public :
        
        view():m_equal("=",this),m_operators(this),m_first_operand(this),m_second_operand(this),m_result(this)
        {
            QGridLayout grid(this);
            m_result.setText("res");

            m_operators.addItem("+",0);
            m_operators.addItem("-",1);
            m_operators.addItem("/",2);
            m_operators.addItem("*",3);


            grid.addWidget(&m_first_operand,0,0);
            grid.addWidget(&m_operators,0,1);
            grid.addWidget(&m_second_operand,0,2);
            grid.addWidget(&m_equal,0,3);
            grid.addWidget(&m_result,0,4);

            show();   
        }   

        ~view()
        {}


};
