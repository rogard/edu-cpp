//[headers
#include <iostream> // 2022
#include <assert.h>
#include <boost/array.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/range.hpp>
#include <boost/type_traits.hpp>
//]

int main (int argc, char * const argv[]) {

	//[explicit
    const int n = 13;
    const char ar[ n ] = {
        'H', 'e', 'l', 'l', 'o', ' ',
        'w', 'o', 'r', 'l', 'd', '!',
        '\0'
    };
	//]

{

    //[implicit
    const char ar[] = "Hello world!";
    //]

	//[bracket
	assert( ar[ 0 ] == 'H' );
	assert( ar[ n - 2 ] == '!' );
	assert( ar[ n - 1 ] == '\0' );
	//]

}

    //[size
    assert( sizeof( ar )/sizeof( ar[ 0 ] ) == n  );
    //]

    //[as_ptr
    const char* ptr = "Hello world!";
	assert( *( ar + 0 ) == *( ptr + 0 ) );
	assert( *( ar + n - 1 ) == *( ptr + n - 1 ) );
    //]

	//[address
	assert( &ar[ 0 ] == ( ar + 0 ) );
	assert( &ar[ n - 1 ] == ( ar + n -1 ) );
    //]

    //[typedef
    typedef const char ar_ [ n ];
    typedef const char* ptr_;
	//]

    //[it
    typedef boost::range_iterator<ar_>::type it_;
    BOOST_MPL_ASSERT(( boost::is_same<ptr_, it_> ));

    assert( boost::begin( ar ) == &ar[ 0 ] );
    assert( boost::end( ar ) == &ar[ n ] );
    //]

	//[rx
    typedef boost::remove_extent<ar_>::type rx_;
    BOOST_MPL_ASSERT(( boost::is_same<rx_, const char> ));
	//]

	//[ref
	typedef boost::add_reference<ar_>::type ref_;
	BOOST_MPL_ASSERT(( boost::is_same<ref_, const char (&) [ n ]> ));
	//]

	//[decay
    typedef boost::decay<ar_>::type decay_;
    BOOST_MPL_ASSERT(( boost::is_same<decay_, ptr_> ));
	//]

    std::cout << "Completed c_array\n";

    return 0;
}
