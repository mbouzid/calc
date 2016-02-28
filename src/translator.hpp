#pragma once

#include <QObject>
#include <Qt/QtGui>

#include "view.hpp"
#include "engine.hpp"

class translator
{
    
    public :
        
        translator()
        {
            view * v = new view ;
            engine * e = new engine ;
            
            // when the equal button is clicked , it will make the calculation
            QObject::connect(&v->m_equal, SIGNAL(clicked()), e , SLOT(calculate())); 
            // on first operand value change it will change it also for the calculation
            QObject::connect(&v->m_first_operand, SIGNAL(valueChanged(int)), e , SLOT(set_first_operand(int))); 
            // same as above for the second operand
            QObject::connect(&v->m_second_operand, SIGNAL(valueChanged(int)), e , SLOT(set_second_operand(int))); 
            // same ... but with the operator
            QObject::connect(&v->m_operators, SIGNAL(currentIndexChanged(int)) , e , SLOT(set_operator(int)));
            // when the value is emitted the label change with the result of the calculation 
            QObject::connect(e, SIGNAL(value(int)), &v->m_result, SLOT(setNum(int)));
        }

        ~translator()
        {;}





};
