
#line 1 "hello.rl"
#include <stdio.h>
#include <string.h>


#line 8 "hello.c"
static const char _hello_key_offsets[] = {
	0, 0, 1, 2, 3, 4, 5
};

static const char _hello_trans_keys[] = {
	104, 101, 108, 108, 111, 0
};

static const char _hello_single_lengths[] = {
	0, 1, 1, 1, 1, 1, 0
};

static const char _hello_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0
};

static const char _hello_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 10
};

static const char _hello_trans_targs[] = {
	2, 0, 3, 0, 4, 0, 5, 0, 
	6, 0, 6, 0
};

static const int hello_start = 1;
static const int hello_first_final = 6;
static const int hello_error = 0;

static const int hello_en_main = 1;


#line 8 "hello.rl"


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *p = argv[1];
    char *pe = p + strlen(p);
    int cs;

    
#line 55 "hello.c"
	{
	cs = hello_start;
	}

#line 21 "hello.rl"
    
#line 62 "hello.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _hello_trans_keys + _hello_key_offsets[cs];
	_trans = _hello_index_offsets[cs];

	_klen = _hello_single_lengths[cs];
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

	_klen = _hello_range_lengths[cs];
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
	cs = _hello_trans_targs[_trans];

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 22 "hello.rl"

    if (cs >= hello_first_final)
        printf("match!\n");
    else
        printf("no match\n");

    return 0;
}