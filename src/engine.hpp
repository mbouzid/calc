#pragma once

#include <QObject>
#include <Qt/QtGui>
#include <iostream>

class engine : public QObject
{

    Q_OBJECT

    private :

        int m_first_operand ;
        char m_operator ;
        int m_second_operand ;        

    public :

        engine()
        {}
        
        ~engine()
        {}

    public slots:
        void set_first_operand( int val )
        {
            m_first_operand=val;
        }
        
        void set_second_operand( int val )
        {
            m_second_operand=val;
        }
        
        void set_operator( int index )
        {
            switch (index)
            {
                case 0 : 
                {
                    m_operator='+';
                    break;
                }
                case 1 : 
                {
                    m_operator='-';
                    break;
                }
                case 2 :
                {
                    m_operator='/';
                    break;
                }
                case 3 : 
                {
                    m_operator='*'; 
                    break;
                }
            }
        }

        void calculate()
        {
            int result=0 ;

            switch (m_operator)
            {
                case '+' :
                {
                    result= m_first_operand+m_second_operand;
                    break;
                }
                case '-' :
                {
                    result= m_first_operand-m_second_operand;
                    break;
                }
                case '/' :
                {
                    result=m_first_operand/m_second_operand;
                    break;
                }
                case '*' :
                {
                    result=m_first_operand*m_second_operand;
                    break;
                }
            }
            
            emit value(result);
        }
    
    signals:
        void value( int result );
};
