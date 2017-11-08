/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file qp_spline_reference_line_smoother.h
 **/

#ifndef MODULES_PLANNING_REFERENCE_LINE_REFERENCE_LINE_SMOOTHER_H_
#define MODULES_PLANNING_REFERENCE_LINE_REFERENCE_LINE_SMOOTHER_H_

#include <vector>

#include "modules/planning/reference_line/reference_line.h"

namespace apollo {
namespace planning {

struct AnchorPoint {
  common::PathPoint path_point;
  double lateral_bound = 0.0;
  double longitudinal_bound = 0.0;
};

class ReferenceLineSmoother {
 public:
  ReferenceLineSmoother() = default;

  virtual ~ReferenceLineSmoother() = default;

  virtual void SetAnchorPoints(
      const std::vector<AnchorPoint>& achor_points) = 0;

  virtual bool Smooth(const ReferenceLine&, ReferenceLine* const) = 0;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_REFERENCE_LINE_REFERENCE_LINE_SMOOTHER_H_
