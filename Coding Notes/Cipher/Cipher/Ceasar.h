#pragma once     // for VS.net
#ifndef CEASAR_H   // Guard Conditional Compilation
#define CEASAR_H

/////////////////////////////////////////////////////////////////////////////
/// \class     Ceasar
/// \author    Jack R. Hagemeister (jackrh)
///
/// \date      3/22/2007
/// \brief     <Short description and purpose of this class>
///
///
/// \invariant
///        -#  First class invariant
///        -#  Next class invariant, .....
/// REVISION HISTORY:
/// DATE       CHANGE
///
/////////////////////////////////////////////////////////////////////////////

// SYSTEM INCLUDES
//
#include <string>
using std::string;
// PROJECT INCLUDES
//
#include <ctype.h>
using std::ctype;
// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

// CONSTANTS
//

class Ceasar
{
public:
   // LIFECYCLE

   /// Default constructor.
   /// \pre             
   /// \post            
   /// \param  (repeat for every parameter)
   /// \return            
   Ceasar(void);

   // OPERATIONS 
   /////////////////////////////////////////////////////////////////////////////
   ///   \name       void encode( void )
   ///   \brief  
   ///   \pre    
   ///   \post   
   ///   \param  
   ///   \return 
   /////////////////////////////////////////////////////////////////////////////
   void encode( void );

   /////////////////////////////////////////////////////////////////////////////
   ///   \name    void decode( void )
   ///   \brief  
   ///   \pre    
   ///   \post   
   ///   \param  
   ///   \return 
   /////////////////////////////////////////////////////////////////////////////
   void decode( void );

   /////////////////////////////////////////////////////////////////////////////
   ///   \name    void setShift( unsigned rotaion )
   ///   \brief  
   ///   \pre    
   ///   \post   
   ///   \param  
   ///   \return 
   /////////////////////////////////////////////////////////////////////////////
   void setShift( unsigned rotaion );


   // ACCESS and MUTATE 
   /////////////////////////////////////////////////////////////////////////////
   ///   \name    setMessage( string message) 
   ///   \brief   set a message in the cipher object
   ///   \pre    
   ///   \post   
   ///   \param  
   ///   \return 
   /////////////////////////////////////////////////////////////////////////////
   void setMessage( string message );

   /////////////////////////////////////////////////////////////////////////////
   ///   \name    string getMessage( void )
   ///   \brief  
   ///   \pre    
   ///   \post   
   ///   \param  
   ///   \return 
   /////////////////////////////////////////////////////////////////////////////
   string getMessage( void );



   // INQUIRY 


private: 
   string   mMessage;
   bool     mEncoded;
   unsigned mShift;



}; 

// INLINE METHODS 
// 

// EXTERNAL REFERENCES 
//

#endif  // Ceasar_H
