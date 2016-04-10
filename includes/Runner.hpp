#ifndef		RUNNER_HPP
# define	RUNNER_HPP

# include "Enemy.hpp"
# include "Character.hpp"

class Runner :  public Enemy{
public:

	Runner( int row, int col );
	Runner( Runner const & obj );

	 ~Runner( void );

	Runner & operator=( Runner const & rhs );

	Runner * clone(void) const;

	void	move( int frame, Character * rhs );

	static char const Symbol = 'Y';
	static int  const HP = 1;
	static int  const Dmg = 1;
	static bool const FF = false;

private:
	Runner( void );
	int _direction;
};
 #endif
