<template>
    <n-modal v-model:show="showModal" transform-origin="center" @negative-click="cancel">
        <n-card style="max-width: 680px" title="添加下载任务" bordered closable @close="cancel">
            <n-form ref="data" :model="model" label-placement="left" label-width="80"
                require-mark-placement="right-hanging">
                <n-grid :cols="24" :x-gap="8">
                    <n-form-item-gi :span="24" label="任务链接" path="url">
                        <n-input v-model:value="model.url" placeholder="url" />
                    </n-form-item-gi>
                    <n-form-item-gi :span="24" label="文件名称" path="url">
                        <n-input-group>
                            <n-input v-model:value="model.name" placeholder="name" />
                            <n-button @click="">规则</n-button>
                        </n-input-group>
                    </n-form-item-gi>
                    <n-form-item-gi :span="24">
                        <n-collapse accordion>
                            <n-collapse-item title="高级设置" name="1">
                                <n-grid :cols="24" :x-gap="8">
                                    <n-form-item-gi :span="24" label="媒体文件" path="dir">
                                        <n-input-group>
                                            <n-select v-model:value="model.video" :options="videoVec"></n-select>
                                            <n-select v-model:value="model.audio" :options="audioVec"></n-select>
                                            <n-select v-model:value="model.subtitles"
                                                :options="subtitlesVec"></n-select>
                                        </n-input-group>
                                    </n-form-item-gi>
                                    <n-form-item-gi :span="24" label="下载目录" path="dir">
                                        <n-input-group>
                                            <n-input v-model:value="model.dir" placeholder="dir" />
                                            <n-button @click="">选择</n-button>
                                        </n-input-group>
                                    </n-form-item-gi>
                                    <n-form-item-gi :span="24" label="解密" path="decrypt.type">
                                        <n-input-group>
                                            <n-select v-model:value="model.decrypt.type" :options="decryptType"
                                                :style="{ width: '20%' }"></n-select>
                                            <n-input v-model:value="model.decrypt.key" placeholder="Key"
                                                :style="{ width: '40%' }" />
                                            <n-input v-model:value="model.name" placeholder="IV"
                                                :style="{ width: '40%' }" />
                                        </n-input-group>
                                    </n-form-item-gi>
                                    <n-form-item-gi :span="21" label="代理" path="proxy.url">
                                        <n-input-group>
                                            <n-input v-model:value="model.proxy.url" :style="{ width: '80%' }"
                                                placeholder="url" />
                                            <n-input v-model:value="model.proxy.port" :style="{ width: '20%' }"
                                                placeholder="port" />
                                        </n-input-group>
                                    </n-form-item-gi>
                                    <n-form-item-gi :span="3" label="" path="proxy.open">
                                        <n-checkbox v-model:checked="model.proxy.open">开启</n-checkbox>
                                    </n-form-item-gi>
                                    <n-form-item-gi :span="24" label="附加头" path="proxy.header">
                                        <n-input v-model:value="model.proxy.header" placeholder="" type="textarea"
                                            :autosize="{
                                                minRows: 3,
                                                maxRows: 5,
                                            }" />
                                    </n-form-item-gi>
                                    <n-form-item-gi :span="24" label="下载结束" path="end">
                                        <n-input-group>
                                            <n-checkbox v-model:checked="model.end.merge">自动合并</n-checkbox>
                                            <n-checkbox v-model:checked="model.end.catch">删除缓存</n-checkbox>
                                            <n-checkbox v-model:checked="model.end.dir">打开目录</n-checkbox>
                                            <n-checkbox v-model:checked="model.end.play">自动播放</n-checkbox>
                                        </n-input-group>
                                    </n-form-item-gi>
                                </n-grid>
                            </n-collapse-item>
                        </n-collapse>
                    </n-form-item-gi>
                </n-grid>
            </n-form>
            <template #action>
                <n-space justify="end">
                    <n-button @click="confirm">确认</n-button>
                    <n-button type="tertiary" @click="cancel">取消</n-button>
                </n-space>
            </template>
        </n-card>
    </n-modal>
</template>

<script setup>
import { defineEmits } from 'vue'
const showModal = defineModel(false, { required: true, default: false })

const emit = defineEmits(['addTaskConfirm', 'addTaskCancel'])

const data = ref(null)
const model = ref({
    url: '', // 链接
    name: '', // 文件名
    video: 'auto', // 视频流
    audio: 'auto', // 音频流
    subtitles: 'auto', // 字幕流
    dir: '',
    decrypt: {
        type: 'AES-128',
        key: '',
        IV: ''
    },
    proxy: {
        url: '',
        port: null,
        open: false,
        header: ''
    },
    end: {
        merge: true,
        catch: true,
        dir: false,
        play: false
    }
})

const videoVec = ref([
    { label: "自动选择画质", value: "auto" },
    { label: "全部选择画质", value: "all" },
    { label: "1920x1080 | 4800Kbps", value: "1920x1080 | 4800Kbps" },
    { label: "1280x720 | 2400Kbps", value: "1280x720 | 2400Kbps" },
    { label: "960x540 | 1200Kbps", value: "960x540 | 1200Kbps" },
    { label: "640x360 | 800Kbps", value: "640x360 | 800Kbps" }
])

const audioVec = ref([
    { label: "自动选择音质", value: "auto" },
    { label: "全部选择音质", value: "all" },
    { label: "4800Kbps", value: "4800Kbps" },
    { label: "2400Kbps", value: "2400Kbps" },
    { label: "1200Kbps", value: "1200Kbps" },
    { label: "800Kbps", value: "800Kbps" }
])

const subtitlesVec = ref([
    { label: "自动选择字幕", value: "auto" },
    { label: "全部选择字幕", value: "all" },
    { label: "中文", value: "zh_cn" },
    { label: "英文", value: "en" },
    { label: "日文", value: "jp" }
])

const decryptType = ref([
    { label: 'AES-128', value: 'AES-128' }
])

function confirm() {
    emit('addTaskConfirm')
    showModal.value = false
}

function cancel() {
    showModal.value = false
}
</script>