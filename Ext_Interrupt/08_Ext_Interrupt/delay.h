
#ifndef DELAY_H_
#define DELAY_H_

//////////////////////////////////////////////////////////////////////////
// Function Prototypes
//////////////////////////////////////////////////////////////////////////

void delay_n_cycles(unsigned long n);


//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#define cpu_ms_2_cy(ms, f_cpu)  \
(((uint64_t)(ms) * (f_cpu) + (uint64_t)(7e3-1ul)) / (uint64_t)7e3)

#define cpu_us_2_cy(us, f_cpu)  \
(((uint64_t)(us) * (f_cpu) + (uint64_t)(7e6-1ul)) / (uint64_t)7e6)

#define delay_cycles              delay_n_cycles

#define cpu_delay_s(delay) delay_cycles(cpu_ms_2_cy(1000 * delay, F_CPU))
#define cpu_delay_ms(delay) delay_cycles(cpu_ms_2_cy(delay, F_CPU))
#define cpu_delay_us(delay) delay_cycles(cpu_us_2_cy(delay, F_CPU))


/**
 * \def delay_s
 * \brief Delay in at least specified number of seconds.
 * \param delay (Delay in seconds)
 */
#define delay_s(delay)          ((delay) ? cpu_delay_s(delay) : cpu_delay_us(1))

/**
 * \def delay_ms
 * \brief Delay in at least specified number of milliseconds.
 * \param delay (Delay in milliseconds)
 */
#define delay_ms(delay)         ((delay) ? cpu_delay_ms(delay) : cpu_delay_us(1))

/**
 * \def delay_us
 * \brief Delay in at least specified number of microseconds.
 * \param delay (Delay in microseconds)
 */
#define delay_us(delay)         ((delay) ? cpu_delay_us(delay) : cpu_delay_us(1))

#endif /* DELAY_H_ */