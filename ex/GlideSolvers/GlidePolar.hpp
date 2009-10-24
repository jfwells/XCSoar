#ifndef GLIDEPOLAR_HPP
#define GLIDEPOLAR_HPP

struct GLIDE_STATE;
struct GLIDE_RESULT;

class GlidePolar
{
public:
  GlidePolar(const double _mc,
             const double _bugs,
             const double _ballast);

  double get_VbestLD() const {
    return VbestLD;
  }
  double get_SbestLD() const {
    return SbestLD;
  }
  void set_mc(const double _mc);
  double get_mc() const {
    return mc;
  }
  double SinkRate(const double V) const;
  double MSinkRate(const double V) const;

  GLIDE_RESULT solve(const GLIDE_STATE &task,
    const double cruise_efficiency=1.0) const;

  GLIDE_RESULT solve_sink(const GLIDE_STATE &task,
                          const double S,
                          const double cruise_efficiency=1.0) const;

private:
  void solve();
  double mc;
  double bugs;
  double ballast;

  double VbestLD;
  double SbestLD;
};

#endif
