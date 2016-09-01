#pragma once

#include "data/properties.h"
#include "gl/framebuffer.h"
#include <mutex>

namespace Tangram {

struct Feature;
class SceneLayer;
class RenderState;

class FeatureSelection {

public:

    FeatureSelection();

    uint32_t colorIdentifier(const Feature& _feature, const SceneLayer& _layer) const;

    // TODO: return true when pending requests for a
    // screen location has been done from the tangram API
    bool pendingRequests() const { return true; }

    void beginRenderPass(RenderState& _rs);

    void endRenderPass(RenderState& _rs);

private:

    mutable std::atomic<uint32_t> m_entry;

    std::unique_ptr<FrameBuffer> m_framebuffer;

};

}