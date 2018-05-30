// Copyright 2014 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef PACKAGER_MEDIA_BASE_MUXER_OPTIONS_H_
#define PACKAGER_MEDIA_BASE_MUXER_OPTIONS_H_

#include <stdint.h>

#include <string>

#include "packager/media/public/mp4_output_params.h"

namespace shaka {
namespace media {

/// This structure contains the list of configuration options for Muxer.
struct MuxerOptions {
  MuxerOptions();
  ~MuxerOptions();

  /// MP4 (ISO-BMFF) specific parameters.
  Mp4OutputParams mp4_params;

  /// Output file name. If segment_template is not specified, the Muxer
  /// generates this single output file with all segments concatenated;
  /// Otherwise, it specifies the init segment name.
  std::string output_file_name;

  /// Output file index. With one file per Representation per Period, there
  /// could be more than one file generated with Ad Cues present. This is the
  /// 0-based index of the output file.
  /// TODO(kqyang): Remove when the EPT adjustment logic in
  /// Fragmenter::FinalizeFragment is removed.
  size_t output_file_index = 0;

  /// Specify output segment name pattern for generated segments. It can
  /// furthermore be configured by using a subset of the SegmentTemplate
  /// identifiers: $RepresentationID$, $Number$, $Bandwidth$ and $Time.
  /// Optional.
  std::string segment_template;

  /// Specify temporary directory for intermediate files.
  std::string temp_dir;

  /// User-specified bit rate for the media stream. If zero, the muxer will
  /// attempt to estimate.
  uint32_t bandwidth = 0;
};

}  // namespace media
}  // namespace shaka

#endif  // PACKAGER_MEDIA_BASE_MUXER_OPTIONS_H_
