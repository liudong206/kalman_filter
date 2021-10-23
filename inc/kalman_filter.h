#ifndef  _KALMAN_FILTER_H
#define  _KALMAN_FILTER_H
#ifdef __cplusplus
/*head file*/
extern "C"
{
#endif
typedef struct {
    float x;  /* state */
    float A;  /* x(n)=A*x(n-1)+u(n),u(n)~N(0,q) */
    float C;  /* z(n)=H*x(n)+w(n),w(n)~N(0,r)   */
    float q;  /* process(predict) noise convariance */
    float r;  /* measure noise convariance */
    float p;  /* estimated error convariance */
    float gain;
} kalman_state;

extern void kalman_init(kalman_state *state, float init_x, float init_p);
extern float kalman_filter(kalman_state *state, float z_measure);

#ifdef __cplusplus
}
#endif
#endif  /*_KALMAN_FILTER_H*/

