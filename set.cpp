
#include "set.h"


int case_insensitive_cmp::operator( ) ( const std::string& s1, const std::string& s2 ) const
{
}


const treenode* find( const treenode* n, const treenode::valtype& val )
{
   treenode::valcmp cmp;


}

treenode** find( treenode** n, const treenode::valtype& val )
{
   treenode::valcmp cmp;


}

size_t size( const treenode* n )
{
}

size_t height( const treenode* n )
{
}

void deallocate( treenode* n )
{
}


treenode* makecopy( const treenode* n ) 
{
}


// Step to the right as long as possible. When we get
// stuck, we are in the rightmost node. Remove it, and
// return it. (Don't delete it.)
// *from cannot be the empty tree.

treenode* extractrightmost( treenode** from )
{
   while( (*from) -> right )
      from = & (*from) -> right;

   treenode* n = *from;
   *from = (*from) -> left;
   return n;
}

void print( std::ostream& out, const treenode* n, unsigned int indent )
{

   for( unsigned int i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


// Both the upperbound and the lowerbound are strict.
// We use pointers, so that they can be absent. 
// Of course, this is a tasteless way of dealing with partiality.

void checkbetween( const treenode* n, 
                   const treenode::valtype* lowerbound, 
                   const treenode::valtype* upperbound ) 
{
   treenode::valcmp cmp;

   while(n) 
   {
      if( lowerbound && cmp( *lowerbound, n -> val ) >= 0 ) 
      {
         std::cout << "value " << ( n -> val );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         throw std::runtime_error( "tree not correct" ); 
      }

      if( upperbound && cmp( *upperbound, n -> val ) <= 0 ) 
      {
         std::cout << "value " << ( n -> val );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         throw std::runtime_error( "tree not correct" );  
      }

      checkbetween( n -> left, lowerbound, &( n -> val ));
      lowerbound = & ( n -> val );
      n = n -> right;
   }
} 


unsigned int log_base2( size_t s )
{
}

bool set::contains( const valtype& val ) const
{ 
}

 
bool set::insert( const valtype& val )
{
}


bool set::remove( const valtype& val )
{
}


size_t set::size( ) const
{
   return ::size( tr );
}

size_t set::height( ) const
{
   return ::height( tr );
}

bool set::empty( ) const
{
}

set:: ~set( )
{
}

void set::clear( )
{
}

set::set( const set& other )
{ }


set& set::operator = ( const set& other )
{
}



void set::checksorted( ) const
{
   ::checkbetween( tr, nullptr, nullptr );
}


void set::print( std::ostream& out, unsigned int indent ) const
{
   ::print( out, tr, indent );
}

