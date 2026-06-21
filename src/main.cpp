#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <chrono>

using namespace geode::prelude;

static std::chrono::steady_clock::time_point g_startTime;
static bool g_sessionActive = false;

$modify(PlayLayer) {
    bool init(GJGameLevel* level, bool p1, bool p2) {
        if (!PlayLayer::init(level, p1, p2)) return false;

        // Only start the timer if a session isn't already active
        // This prevents the timer from resetting every time you respawn
        if (!g_sessionActive) {
            g_startTime = std::chrono::steady_clock::now();
            g_sessionActive = true;

            bool isPractice = this->m_isPracticeMode;
            log::info("Playtest Session Started: {} (Practice: {})",
                      level->m_levelName, isPractice ? "Yes" : "No");
        }

        return true;
    }

    void onQuit() {
        if (g_sessionActive) {
            auto endTime = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(endTime - g_startTime).count();

            log::info("SESSION_RESULT: {}s", elapsed);
            g_sessionActive = false;
        }
        PlayLayer::onQuit();
    }
