int fsqrt(int n)
{
	union {
		float f;
		uint32_t i;
	} rep = { .f = (float)n };
	rep.i = 0x5f3759df - (rep.i >> 1);
	rep.f *= 1.5f - (n * 0.5F * rep.f * rep.f);
	return (int)(1 / rep.f);
}
