/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "presto_cpp/main/common/Counters.h"
#include "velox/common/base/StatsReporter.h"

namespace facebook::presto {

void registerPrestoMetrics() {
  DEFINE_METRIC(
      kCounterDriverCPUExecutorQueueSize, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterDriverCPUExecutorLatencyMs, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterHTTPExecutorLatencyMs, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumHTTPRequest, facebook::velox::StatType::COUNT);
  DEFINE_METRIC(kCounterNumHTTPRequestError, facebook::velox::StatType::COUNT);
  DEFINE_METRIC(kCounterHTTPRequestLatencyMs, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterHttpClientPrestoExchangeNumOnBody,
      facebook::velox::StatType::COUNT);
  DEFINE_HISTOGRAM_METRIC(
      kCounterHttpClientPrestoExchangeOnBodyBytes,
      1000,
      0,
      1000000,
      50,
      90,
      95,
      99,
      100);
  DEFINE_HISTOGRAM_METRIC(
      kCounterPrestoExchangeSerializedPageSize,
      10000,
      0,
      10000000,
      50,
      90,
      95,
      99,
      100);
  DEFINE_METRIC(kCounterNumQueryContexts, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumTasks, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumTasksRunning, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumTasksFinished, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumTasksCancelled, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumTasksAborted, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumTasksFailed, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumZombieVeloxTasks, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumZombiePrestoTasks, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumTasksWithStuckOperator, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumTasksDeadlock, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumTaskManagerLockTimeOut, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumQueuedDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumOnThreadDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumSuspendedDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForConsumerDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForSplitDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForProducerDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForJoinBuildDrivers,
      facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForJoinProbeDrivers,
      facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForMergeJoinRightSideDrivers,
      facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForMemoryDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForConnectorDrivers,
      facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterNumBlockedWaitForSpillDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumBlockedYieldDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterNumStuckDrivers, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterTotalPartitionedOutputBuffer, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterPartitionedOutputBufferGetDataLatencyMs,
      facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterOsUserCpuTimeMicros, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterOsSystemCpuTimeMicros, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterOsNumSoftPageFaults, facebook::velox::StatType::AVG);
  DEFINE_METRIC(kCounterOsNumHardPageFaults, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterOsNumVoluntaryContextSwitches, facebook::velox::StatType::AVG);
  DEFINE_METRIC(
      kCounterOsNumForcedContextSwitches, facebook::velox::StatType::AVG);
  DEFINE_HISTOGRAM_METRIC(
      kCounterExchangeSourcePeakQueuedBytes,
      1l * 1024 * 1024 * 1024,
      0,
      62l * 1024 * 1024 * 1024, // max bucket value: 62GB
      100);

  /// ================== Disk Spilling Counters =================

  DEFINE_METRIC(kCounterSpillRuns, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpilledFiles, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpilledRows, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpilledBytes, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpillFillTimeUs, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpillSortTimeUs, facebook::velox::StatType::SUM);
  DEFINE_METRIC(
      kCounterSpillSerializationTimeUs, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpillWrites, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpillFlushTimeUs, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpillWriteTimeUs, facebook::velox::StatType::SUM);
  DEFINE_METRIC(kCounterSpillMemoryBytes, facebook::velox::StatType::AVG);
  DEFINE_HISTOGRAM_METRIC(
      kCounterSpillPeakMemoryBytes,
      1l * 512 * 1024 * 1024,
      0,
      20l * 1024 * 1024 * 1024, // max bucket value: 20GB
      100);
  DEFINE_METRIC(kCounterSpillMaxLevelExceeded, facebook::velox::StatType::SUM);

  // NOTE: Metrics type exporting for file handle cache counters are in
  // PeriodicTaskManager because they have dynamic names. The following counters
  // have their type exported there:
  // [
  //  kCounterHiveFileHandleCacheNumElementsFormat,
  //  kCounterHiveFileHandleCachePinnedSizeFormat,
  //  kCounterHiveFileHandleCacheCurSizeFormat,
  //  kCounterHiveFileHandleCacheNumAccumulativeHitsFormat,
  //  kCounterHiveFileHandleCacheNumAccumulativeLookupsFormat
  // ]
}

} // namespace facebook::presto
