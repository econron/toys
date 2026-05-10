
#line 1 "vowels.rl"
#include <stdio.h>
#include <string.h>


#line 8 "vowels.c"
static const char _counter_actions[] = {
	0, 1, 0
};

static const char _counter_key_offsets[] = {
	0
};

static const char _counter_trans_keys[] = {
	97, 101, 105, 111, 117, 0
};

static const char _counter_single_lengths[] = {
	5
};

static const char _counter_range_lengths[] = {
	0
};

static const char _counter_index_offsets[] = {
	0
};

static const char _counter_indicies[] = {
	1, 1, 1, 1, 1, 0, 0
};

static const char _counter_trans_targs[] = {
	0, 0
};

static const char _counter_trans_actions[] = {
	0, 1
};

static const int counter_start = 0;
static const int counter_first_final = 0;
static const int counter_error = -1;

static const int counter_en_main = 0;


#line 12 "vowels.rl"


int main(int argc, char **argv) {
    char *p = argv[1];
    char *pe = p + strlen(p);
    int cs;
    int vowels = 0;

    
#line 62 "vowels.c"
	{
	cs = counter_start;
	}

#line 21 "vowels.rl"
    
#line 69 "vowels.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
_resume:
	_keys = _counter_trans_keys + _counter_key_offsets[cs];
	_trans = _counter_index_offsets[cs];

	_klen = _counter_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _counter_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _counter_indicies[_trans];
	cs = _counter_trans_targs[_trans];

	if ( _counter_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _counter_actions + _counter_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 7 "vowels.rl"
	{ vowels++; }
	break;
#line 145 "vowels.c"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	}

#line 22 "vowels.rl"

    printf("vowels: %d\n", vowels);
    return 0;
}