#include "timer.hpp"

#include "interrupt.hpp"

namespace {
  const uint32_t kCountMax = 0xffffffffu;
  volatile uint32_t& lvt_timer = *reinterpret_cast<uint32_t*>(0xfee00320);
  volatile uint32_t& initial_count = *reinterpret_cast<uint32_t*>(0xfee00380);
  volatile uint32_t& current_count = *reinterpret_cast<uint32_t*>(0xfee00390);
  volatile uint32_t& divide_config = *reinterpret_cast<uint32_t*>(0xfee003e0);
}

// #@@range_begin(init_timer)
void InitializeLAPICTimer() {
  timer_manager = new TimerManager;

  divide_config = 0b1011; // divide 1:1
  lvt_timer = (0b010 << 16) | InterruptVector::kLAPICTimer; // not-masked, periodic
  initial_count = 0x1000000u;
}
// #@@range_end(init_timer)

void StartLAPICTimer() {
  initial_count = kCountMax;
}

uint32_t LAPICTimerElapsed() {
  return kCountMax - current_count;
}

void StopLAPICTimer() {
  initial_count = 0;
}

// #@@range_begin(timermgr_tick)
void TimerManager::Tick() {
  ++tick_;
}

TimerManager* timer_manager;

void LAPICTimerOnInterrupt() {
  timer_manager->Tick();
}
// #@@range_end(timermgr_tick)